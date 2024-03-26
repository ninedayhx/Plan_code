clear all;
close all;
clc;

t = 0:0.1:10; 
p = [-1/20,1,0];
y = polyval(p,t);

figure(1);
plot(t,y,'o');
hold on
plot(0,2.5,'*');
xlim([-10,10]);