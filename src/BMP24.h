// BMP24.h
//

#ifndef BMP24_H
#define BMP24_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <stdint.h>
#include <iostream>

typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef uint32_t LONG;

struct BMPFileHeader {
    //WORD bfType;            //specifies the file type
    DWORD bfSize;			// bytes of entire file
    WORD bfReserved1;		// nothing
    WORD bfReserved2;		// nothing
    DWORD bfOffBits;		// address of bitmap data in file
};

struct BMPInfoHeader {
    DWORD biSize;			    // size of this BMPInfoHeader
    int32_t biWidth;
    int32_t biHeight;
    WORD biPlanes;			    // 1 plane, so this equals 1
    WORD biBitCount;		    // 24 bits/pixel
    DWORD biCompression;	    // 0 = BMP
    DWORD biSizeImage;		    // size of actual bitmap image
    int32_t biXPelsPerMeter;    // horizontal resolution
    int32_t biYPelsPerMeter;    // vertical resolution
    DWORD biClrUsed;		    // 0
    DWORD biClrImportant;	    // 0 important colors (very old)
};

class BMP24 {
public:
    BMP24 (int width, int height) {
        int imageBytes = width * height * 3;
        m_imageData = new char[imageBytes];

        m_magic = new char[2];
        m_magic[0] = 'B';
        m_magic[1] = 'M';

        //m_bitmapFileHeader.bfType = 0x4D42;
        m_bitmapFileHeader.bfSize = 2 + sizeof (BMPFileHeader)
                                    + sizeof (BMPInfoHeader) + imageBytes;
        m_bitmapFileHeader.bfReserved1 = 0;
        m_bitmapFileHeader.bfReserved2 = 0;
        m_bitmapFileHeader.bfOffBits = 2 + sizeof (BMPFileHeader)
                                       + sizeof (BMPInfoHeader);
        m_bitmapInfoHeader.biSize = sizeof (BMPInfoHeader);
        m_bitmapInfoHeader.biWidth = width;
        m_bitmapInfoHeader.biHeight = height;
        m_bitmapInfoHeader.biPlanes = 1;
        m_bitmapInfoHeader.biBitCount = 24;		// bits/pixel
        m_bitmapInfoHeader.biCompression = 0;		// no compression
        m_bitmapInfoHeader.biSizeImage = imageBytes;
        m_bitmapInfoHeader.biXPelsPerMeter = 2835;	// 72 pixels/inch = 2834.64567 pixels per meter
        m_bitmapInfoHeader.biYPelsPerMeter = 2835;
        m_bitmapInfoHeader.biClrUsed = 0;
        m_bitmapInfoHeader.biClrImportant = 0;

        background (0, 0, 0);
    }
    virtual ~BMP24 () {
        delete [] m_imageData;
        delete [] m_magic;
    }
    void set (int x, int y, char r, char g, char b) {
        int width = m_bitmapInfoHeader.biWidth;
        int height = m_bitmapInfoHeader.biHeight;
        if (x < 0 || x >= width || y < 0 || y >= height) return;
        

        m_imageData[((y * width) + x) * 3] = b;
        m_imageData[((y * width) + x) * 3 + 1] = g;
        m_imageData[((y * width) + x) * 3 + 2] = r;
    }
    void get (int x, int y, char& r, char& g, char& b) {
        int height = m_bitmapInfoHeader.biHeight;
        int width = m_bitmapInfoHeader.biWidth;
        if (x < 0 || x >= width || y < 0 || y >= height) {
            //std::cout << "out " << width << " " << height << std::endl;
            return;
        }

        b = m_imageData[((y * width) + x) * 3];
        g = m_imageData[((y * width) + x) * 3 + 1];
        r = m_imageData[((y * width) + x) * 3 + 2];
    }
    void background (char r, char g, char b) {
        int width = m_bitmapInfoHeader.biWidth;
        int height = m_bitmapInfoHeader.biHeight;

        for (int x = 0; x < width; ++x)  {
            for (int y = 0; y < height; ++y)  {
                set (x, y, r, g, b);
            }
        }
    }
    void line (int x0, int y0, int x1, int y1, char r, char g, char b,
               bool vert = false) {
        int mx0 = x0;
        int mx1 = x1;
        int my0 = y0;
        int my1 = y1;

        if (vert) {
            my0 = x0;
            my1 = x1;
            mx0 = y0;
            mx1 = y1;
        }

        double yincr = (my1 - my0) / (mx1 - mx0);
        double y = my0;

        for (int x = mx0; x < mx1; ++x) {
            if (vert)
                set (y, x, r, g, b);
            else
                set (x, y, r, g, b);
            y += yincr;
        }
    }
    void grid (int xdiv, int ydiv, char r, char g, char b) {
        int width = m_bitmapInfoHeader.biWidth;
        int height = m_bitmapInfoHeader.biHeight;
        int xstep = width / xdiv;
        int ystep = height / ydiv;

        for (int x = 0; x < width; x += xstep) {
            line (x, 0, x, height, r, g, b, true);
        }
        for (int y = 0; y < height; y += ystep) {
            line (0, y, width, y, r, g, b);
        }
    }
    void save (const std::string& name) {
        std::ofstream out (name.c_str (), std::ios::binary);
        if (!out.good ())
            throw std::runtime_error ("cannot create output file");

        out.write ((char*) m_magic, 2 * sizeof (char));
        out.write ((char*) &m_bitmapFileHeader, sizeof (m_bitmapFileHeader));
        out.write ((char*) &m_bitmapInfoHeader, sizeof (m_bitmapInfoHeader));
        out.write ((char*) m_imageData, m_bitmapInfoHeader.biSizeImage * sizeof (char));
        out.close ();
    }
    void load (const std::string& name) {
        std::ifstream in (name.c_str ());
        if (!in.good ()) {
            throw std::runtime_error ("cannot open input file");
        }

        in.read ((char*) m_magic, 2 * sizeof (char));

        if (m_magic[0] != 'B' || m_magic[1] != 'M') {
            throw std::runtime_error ("invalid file format; only bitmap supported");
        }

        in.read ((char*) &m_bitmapFileHeader, sizeof (m_bitmapFileHeader));
        in.read ((char*) &m_bitmapInfoHeader, sizeof (m_bitmapInfoHeader));
        if (m_bitmapInfoHeader.biCompression != 0 || m_bitmapInfoHeader.biHeight <= 0
            || m_bitmapInfoHeader.biWidth <= 0) {
            throw std::runtime_error ("invalid image geometry or compressed bitmap");
        }
        delete [] m_imageData;
        m_imageData = new char[m_bitmapInfoHeader.biSizeImage];

        in.read ((char*) m_imageData, m_bitmapInfoHeader.biSizeImage);
        in.close ();
    }
    char* data () const {
        return m_imageData;
    }
    int width () const {
        return m_bitmapInfoHeader.biWidth;
    }
    int height () const {
        return m_bitmapInfoHeader.biHeight;
    }
protected:
    char* m_imageData;
    char* m_magic;

    BMPFileHeader m_bitmapFileHeader;
    BMPInfoHeader m_bitmapInfoHeader;
};

#endif	// BMP24_H

// EOF
