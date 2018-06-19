function run_anarkid (path, target, pconfig)
    close all
    system ([path '/anarkid ' target ' ' pconfig]);
    f = textread ('fitness.txt');
    t = textread ('target.txt');
    b = textread ('best_solution.txt');
    
    subplot (2, 1, 1)
    plot (f)
    title ('Fitness')
    subplot (2,1, 2)
    plot (t)
    hold on
    plot (b, 'r')
    title ('Target vs approximation')
    
end