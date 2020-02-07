clc;
clear all;
close all;
figure(1);
CT=imread('Tiger.jpg');
imshow(CT);
GT=rgb2gray(CT);
imshow(GT);
canny_tiger=edge(GT,'canny',[0.25 0.4],1);
figure(2);
imshow(canny_tiger);

figure(3);
CP=imread('Pig.jpg');
imshow(CP);
GP=rgb2gray(CP);
imshow(GP);
canny_pig=edge(GP,'canny',[0.15 0.3], 0.5);
figure(4);
imshow(canny_pig);