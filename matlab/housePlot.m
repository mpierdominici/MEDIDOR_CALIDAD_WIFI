clear all;
close all;
cosina=fileOpen('COSINA.CSV');
living1=fileOpen('LIVING1.CSV');
living2=fileOpen('LIVING2.CSV');
pcx=fileOpen('PCX.CSV');
a=intensitiDistortion('WIFI Pier',cosina);
b=intensitiDistortion('WIFI Pier',living1);
c=intensitiDistortion('WIFI Pier',living2);
d=intensitiDistortion('WIFI Pier',pcx);
inetn = [a(1,1) b(1,1) c(1,1) d(1,1) ];
intent=[d(1,2) 0 a(1,2) ;b(1,2) 0 0 ;c(1,2) 0 0];
y=[1 2 3 1];
x=[2 1 1 1];
surf(1:3,1:3,intent);
% cosina1=textscan(cosina,'%s%f%f','delimiter',',');
% fclose(cosina);
% cosina2=cell(length(cosina1{1}),3);
% cosina2(:,1)=cosina1{1};
% for i=2:3
%     
%    cosina2(:,i)=num2cell(cosina1{i});
%     
% end
