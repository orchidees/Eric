% Basic plotting and evaluation tool for orchestration.
%
% eval_orchestrate(path, target, pconfig, plot)
%
% arguments: 
% path = location of binary orchestrate
% target = path of target sound file (WAV, 16 bit, 44100)
% pconfig = path of configuration script
% plot [0|1] = determines if figures must be done or not
%
% The error is computed using the MAPE measure.
%
% NB: this script assumes SR=44100

function [t, b] = eval_orchestrate(path, target, pconfig, plt)
    
   close all
   system ([path '/orchestrate ' target ' ' pconfig]);
  
   s = textread ('segments.txt');
   
   tot_err = 0;
   for i = 1:s
       f = textread (sprintf('segment.%04d.fitness.txt', i)); %#ok<*DTXTRD>
       t = textread ( sprintf('segment.%04d.features.txt', i));
       b = textread (sprintf('segment.%04d.best_forecast.txt', i));
      
       if (plt == 1)
           figure
           subplot (2, 1, 1)
           plot (f)
           title (sprintf ('Segment %d - Fitness', i))
           subplot (2,1, 2)
           plot (t)
           hold on
           plot (b, 'r')
           title (sprintf ('Segment %d - Target vs approximation', i)) 
       end
       
       err = mape (t, b);
       fprintf ('segment %04d - error %g\n', i, err)
       tot_err = tot_err + err;
   end
   
   fprintf ('\ntotal average error: %g \n', tot_err / i)
end
