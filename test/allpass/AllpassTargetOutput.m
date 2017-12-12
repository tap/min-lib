% @file
% @ingroup 	min-lib
% 
% @brief 		Generates the Expected Target Output for Allpass tests using Octave
%
% @author		Nathan Wolek
% @copyright	Copyright (c) 2017 Nathan Wolek
% @license		This project is released under the terms of the MIT License.

clear

% Calls to the impz() function require the signal package be loaded first.
% Reference here: https://octave.sourceforge.io/signal/function/impz.html
pkg load signal

% The first variables in this file are used to vary the target outputs.
% We use them to consistently generate different targets for unit testing.
% - samples_to_output controls the number of samples in each target output matrix.

samples_to_output = 64;

% Generate an impulse response with the follow characteristics:
% Allpass, 1 sample delay, 0.5 gain
a1 = [0.5, 1.0]; % fir coefficients
b1 = [1.0, 0.5]; % iir coefficients

output_1_sample_delay = impz(a1, b1, samples_to_output);

% Generate an impulse response with the follow characteristics:
% Allpass, 4 sample delay, 0.5 gain
a2 = [0.5, 0.0, 0.0, 0.0, 1.0];
b2 = [1.0, 0.0, 0.0, 0.0, 0.5];

output_4_samples_delay = impz(a2, b2, samples_to_output);

% Generate an impulse response with the follow characteristics:
% Allpass, 2 sample delay, 0.75 gain
a3 = [0.75, 0.0, 1.0];
b3 = [1.0, 0.0, 0.75];

output_2_samples_delay = impz(a3, b3, samples_to_output);

% Generate an impulse response with the follow characteristics:
% Allpass, 12 sample delay, 0.99 gain
a4 = [0.99, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0];
b4 = [1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.99];

output_12_samples_delay = impz(a4, b4, samples_to_output);

% Generate an impulse response with the follow characteristics:
% Allpass, 8 sample delay, 0.05 gain
a5 = [0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0];
b5 = [1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05];

output_8_samples_delay = impz(a5, b5, samples_to_output);

save expectedOutput.mat output_1_sample_delay
save -append expectedOutput.mat output_4_samples_delay
save -append expectedOutput.mat output_2_samples_delay
save -append expectedOutput.mat output_12_samples_delay
save -append expectedOutput.mat output_8_samples_delay