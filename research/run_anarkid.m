function [t, b] = run_anarkid(path, target, pconfig)
   figure
   % freqs = [0:(22050/1024):o22050]; % assumes SR=44100
    
   
   system ([path '/anarkid ' target ' ' pconfig]);
    f = textread ('target_000_fitness.txt');
    t = textread ('target_000_features.txt');
    b = textread ('target_000_best_forecast.txt');
    
    
    subplot (2, 1, 1)
    plot (f)
    title ('Fitness')
    subplot (2,1, 2)
    %plot (freqs, t)
    plot (t)
    hold on
    %plot (freqs, b, 'r')
    plot (b, 'r')
    title ('Target vs approximation')
    
end
