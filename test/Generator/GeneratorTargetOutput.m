% @file
% @ingroup 	jamoma2
% 
% @brief 		Generates the Expected Target Output for Generators using Octave
%
% @author		Nathan Wolek
% @copyright	Copyright (c) 2015-2017 Nathan Wolek
% @license		This project is released under the terms of the MIT License.

clear

% The first two variables in this file are used to vary the target outputs.
% We use them to generate different targets for unit testing.
% - samples_to_output controls the number of samples in each target output matrix.
% - cycles_per_matrix controls the number of cycles in each target output matrix.

samples_to_output = 64;
cycles_per_matrix = 1;

% samples_per_cycle is then computed using the first two variables.
% This value is needed before we enter the loop that generates each target output matrix.
samples_per_cycle = samples_to_output / cycles_per_matrix;

output_ramp = double (1 : samples_to_output);
output_unipolarramp = double (1 : samples_to_output);
output_sine = double (1 : samples_to_output);
output_unipolarsine = double (1 : samples_to_output);
output_cosine = double (1 : samples_to_output);
output_unipolarcosine = double (1 : samples_to_output);
output_triangle = double (1 : samples_to_output);
output_unipolartriangle = double (1 : samples_to_output);

% the following function is adapted from the code in JamomaGenerators
function retval = generate_trangle(delta)
	retval = 0.0;
	if ( delta <= 0.25 )
		retval = delta / 0.25;
	elseif ( delta >= 0.75 )
		retval = -1.0 + (delta - 0.75) / 0.25;
	else
		retval = 1.0 - (delta - 0.25) / 0.25;
	endif
endfunction

function retval = generate_unipolartrangle(delta)
	retval = 0.0;
	if ( delta <= 0.25 )
		retval = delta / 0.5;
	elseif ( delta >= 0.75 )
		retval = 1.0 + (delta - 1.5) / 0.5;
	else
		retval = -2.0 - (delta - 1.5) / 0.5;
	endif
		retval = retval + 0.5;
endfunction

for i = 1:samples_to_output
	current_delta = mod((i - 1), samples_per_cycle) / samples_per_cycle;
	output_ramp(i) = ( current_delta * 2.0 ) - 1.0;
    output_unipolarramp(i) = current_delta;
	output_sine(i) = sin (current_delta * 2.0 * pi);
	output_unipolarsine(i) = 0.5 + 0.5 * sin (current_delta * 2.0 * pi);
	output_cosine(i) = cos (current_delta * 2.0 * pi);
	output_unipolarcosine(i) = 0.5 + 0.5 * cos (current_delta * 2.0 * pi);
	output_triangle(i) = generate_trangle(current_delta);
	output_unipolartriangle(i) = generate_unipolartrangle(current_delta);
endfor

save expectedOutput.mat output_ramp
save -append expectedOutput.mat output_unipolarramp
save -append expectedOutput.mat output_sine
save -append expectedOutput.mat output_unipolarsine
save -append expectedOutput.mat output_cosine
save -append expectedOutput.mat output_unipolarcosine
save -append expectedOutput.mat output_triangle
save -append expectedOutput.mat output_unipolartriangle
