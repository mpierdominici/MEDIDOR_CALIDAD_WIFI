function [ meas ] = intensitiDistortion( network2analize,data )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
channel=data(strcmpi(data(:,1),network2analize),:);
channel=cell2mat(channel(3));
intensiti=data(strcmpi(data(:,1),network2analize),:);
intensiti=cell2mat(intensiti(2));

inSameCahnnel=data(cell2mat(data(:,3))==channel,:);
inSameCahnnel=data(~strcmpi(data(:,1),network2analize),:);
totalPower=(10.^(cell2mat(inSameCahnnel(:,2))./10)).*(10^-3);
ratioPower=sum(totalPower)/((10^(intensiti/10))*(10^-3));
meas=[intensiti , ratioPower];
end

