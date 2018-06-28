function [S, nc, seg_output] = get_segments (fname, vis)
    [y, fs] = audioread (fname);
    y = mean (y, 2);
    
    m = spectrogram (y, 4096, 2048);
    m = abs (m);
    m = m(1:512, :)';
    n = size(m, 1);
    s_frame = n / (length(y) / fs);
    
    S = m * m';
    if(vis)
        figure;
        imagesc(S);
    end
    
    winLen = 8;

    nc = diag(S);

    th = medfilt1(nc, winLen);
    ispeak = zeros(1, n);
    for i = 1:n-1
        if((nc(i) > nc(i+1)) && (nc(i) > nc(i-1)) && (nc(i) > th(i)))
            ispeak(i) = 1;
        end
    end
    
    if(vis)
        figure;
        plot(nc, 'green')
        hold on
        plot(th, 'b');
        hold on
        plot(ispeak, 'black');
    end 
    
    seg_output = [];
    for i = 1:length(ispeak)
        if(ispeak(i) ~= 0)
            seg_output = [seg_output, i /s_frame];
        end
    end
    if(seg_output(end) < (length(ispeak) /s_frame - 6))
        seg_output = [seg_output, length(ispeak) /s_frame];
    end
    
    if (vis)
        markers = zeros (1, length (y));
        pos = max (0, round(seg_output*fs) - 2048);
        markers(pos) = 1;
       figure;
       plot (y);
       hold on
       plot (markers, 'r');
    end
end
