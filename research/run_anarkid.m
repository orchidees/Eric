function run_anarkid (path, target, pconfig)
    close all
   % freqs = [0:(22050/1024):22050]; % assumes SR=44100
    
   system ([path '/anarkid ' target ' ' pconfig]);
    f = textread ('fitness.txt');
    t = textread ('target.txt');
    b = textread ('best_solution.txt');
    
    
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