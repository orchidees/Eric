%% plot computed feature space

A = importdata ('CSOL_ordinario_mfcc.txt', ' ', 1);
mfcc = A.data;
mfcc_wind = mfcc(find (A.textdata, 'Wind'));

B = importdata ('CSOL_ordinario_spectrum.txt', ' ', 1);
spec = B.data;

C = importdata ('CSOL_ordinario_moments.txt', ' ', 1);
mome = C.data;

%%

[coeff, score] = pca(spec);
reducedDimension = coeff(:,1:3);
reducedData = spec * reducedDimension;

%%
figure 
imagesc (mfcc)

figure
scatter3 (mfcc(:, 1), mfcc(:, 2), mfcc(:, 3));

figure
scatter3 (mfcc(:, 1), mfcc(:, 2), mfcc(:, 3));

%%

figure 
imagesc (mome)

figure
scatter (mome(:, 1), mome(:, 2));

%%

figure 
imagesc (spec(:, 1:256)')

figure
scatter3 (spec(:, 1), spec(:, 2), spec(:, 3));

figure
scatter3 (reducedData(:, 1), reducedData(:, 2), reducedData(:, 3));

