%% MAPE Mean absolute percentage error
function meanPctDiff = mape (testSignal, referenceSignal)
    deltaSignal = abs(testSignal - referenceSignal);
    relDifference = deltaSignal / (referenceSignal + eps); % x by element.
    meanPctDiff = mean (relDifference) * 100; % Average percentage over all elements.
end