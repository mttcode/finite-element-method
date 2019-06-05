clear all;
clc;

disp('MKP: Uloha 1b');
fprintf('\n');
fprintf('\n');
fprintf('\n');

%interval
a_l = 0;
b_p = 1;

%krok
n = 10;
h = (b_p - a_l)/n;

%iteracia xk = h*k + x0
x0 = h*0 + a_l;
x1 = h*1 + x0;
x2 = h*2 + x0;
x3 = h*3 + x0;
x4 = h*4 + x0;
x5 = h*5 + x0;
x6 = h*6 + x0;
x7 = h*7 + x0;
x8 = h*8 + x0;
x9 = h*9 + x0;

disp('Tvar: Au = b');
fprintf('\n');
fprintf('\n');
fprintf('\n');

%matica iteracii
A = [-2 + a_2(x1)*h^2, 1 + a_1(x1)*h/2, 0,0,0,0,0,0,0; 1 - a_1(x2)*h/2, -2 + a_2(x2)*h^2, 1 + a_1(x2)*h/2, 0,0,0,0,0,0; 0, 1 - a_1(x3)*h/2, -2 + a_2(x3)*h^2, 1 + a_1(x3)*h/2, 0,0,0,0,0; 0,0,1 - a_1(x4)*h/2, -2 + a_2(x4)*h^2, 1 + a_1(x4)*h/2, 0,0,0,0; 0,0,0, 1 - a_1(x5)*h/2, -2 + a_2(x5)*h^2, 1 + a_1(x5)*h/2,0,0,0; 0,0,0,0, 1 - a_1(x6)*h/2, -2 + a_2(x6)*h^2, 1 + a_1(x6)*h/2, 0,0; 0,0,0,0,0, 1 - a_1(x7)*h/2, -2 + a_2(x7)*h^2, 1 + a_1(x7)*h/2, 0; 0,0,0,0,0,0, 1 - a_1(x8)*h/2, -2 + a_2(x8)*h^2, 1 + a_1(x8)*h/2; 0,0,0,0,0,0,0,1 - a_1(x9)*h/2, -2 + a_2(x9)*h^2];

disp('A =');
disp(A);

%zac.podmienky
u0 = 2;
u10 = 1;


%matica pravych stran
b = [f_x(x1)*h^2-u0; f_x(x2)*h^2; f_x(x3)*h^2; f_x(x4)*h^2; f_x(x5)*h^2; f_x(x6)*h^2; f_x(x7)*h^2; f_x(x8)*h^2; f_x(x9)*h^2-u10];

disp('b =');
disp(b);

%vypocet neznamych premennych u cez inverznu maticu
u = inv(A)*b;

%rozsah hodnot x s krokom h
x = 0:h:b_p;

%zostrojenie prazdneho okna pre graf
graf = figure(1);

%urcenie pozicie a velkosti prazdneho okna pre graf
set(graf, 'Position', [50 50 800 600]);

%rozsah hodnot premennej u s pociatocnymi hodnotami
u = [u0; u; u10];

fprintf('\n');
fprintf('\n');
disp('Tvar: u = inv(A)*b');
fprintf('\n');
fprintf('\n');
disp('u =');
disp(u);

%vykreslenie grafu funkcie
plot(x, u);

%popis grafu
title('Uloha 1b');
xlabel('x');
ylabel('u');
grid on
