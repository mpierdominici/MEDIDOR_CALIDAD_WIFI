function [ data ] = fileOpen( path )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
file=fopen(path);
dataparsed=textscan(file,'%s%f%f','delimiter',',');
fclose(file);
data=cell(length(dataparsed{1}),3);
data(:,1)=dataparsed{1};
for i=2:3
    
   data(:,i)=num2cell(dataparsed{i});
    
end

end

