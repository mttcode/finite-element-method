function MKP_4(diag_pod, diag_hlavna, diag_nad, b)


% Vstup: 
%
% MKP_4( poddiagonalny vektor, diagonalny vektor, naddiagonalny vektor,
% prava strana )
%
% MKP_4( [1x(N-1)], [1x(N)], [1x(N-1)], [1x(N)] )
%
%
%
% Priklad pouzitia:
%
% Priklad_1: MKP_4( [1x10], [1x11], [1x10], [1x11] )
%
% MKP_4( [5 5 8 8 1 1 0 0 0 4], [5 8 9 1 4 7 8 5 3 1 1], [1 1 1 3 3 2 5 5 4
% 7], [-1 6 -4 7 3 -1 -1 0 0 1 -4] )
%
%
% Priklad_2: MKP_4( 1x3, 1x4, 1x3, 1x4 )
%
% MKP_4( [1 1 1], [2 2 2 2], [1 1 1], [1 2 3 4] )



clc;

fprintf('Riesic trojdiagonalnych matic');
fprintf('\n\n\n\n');

%pocet prvkov na diagonale
N = length(diag_hlavna);

%obdlznikova matica, pocet prvkov na diagonale = pocet riadkov, pocet
%stlpcov = pocet riadkov + 1
matica = zeros(N, N+1);


%zadanie poddiagonalnych prvkov do matice pod diagonalou
for i=1:1:(N-1)

    matica(i+1, i) = diag_pod(i);
    
end

%zadanie diagonalnych prvkov do matice na diagonale
for i=1:1:(N)

    matica(i, i) = diag_hlavna(i);
    
end

%zadanie naddiagonalnych prvkov do matice nad diagonalou
for i=1:1:(N-1)

    matica(i, i+1) = diag_nad(i);
    
end

%zadanie prvkov pravej strany do matice v tvare stlpca na pravo od
%stvorcovej diagonalnej matice
for i=1:1:(N)

    matica(i, N+1) = b(i);
    
end


disp('Vstupne udaje:');
fprintf('\n');

fprintf('Poddiagonalny vektor =');
disp(diag_pod);

fprintf('Diagonalny vektor =');
disp(diag_hlavna);

fprintf('Naddiagonalny vektor =');
disp(diag_nad);

fprintf('Prava strana =');
disp(b);

fprintf('\n\nZapis vstupov do matice =\n\n');
disp(matica);


%vytorenie jednotkovej matice (poddiagonalnej/podtrojuholnikovej)
pod_diag = eye(N);


%Gaussova eliminacna metoda
for i = 1:1:(N-1)
   for j = i+1:1:N
       
       %poddiagonalna matica (podtrojuholnikova)
       pod_diag(j,i) = matica(j, i) / matica(i, i);
       
       %nasobenie a odcitanie riadkov
	   matica(j,:) = matica(j, :) - pod_diag(j, i) * matica(i, :);
       
   end
end


%nulova matica pre prepocet prvkov matice matica()
riesenie_matice = zeros(N, N+1);


%vytvorenie jednotiek na hlavnej diagonale
for i = 1:1:(N)
    for j = 1:1:(N+1)
       
        %delenie vsetkych prvkov riadku diagonalnym prvkom pre dany riadok
        riesenie_matice(i, j) = matica(i, j) / matica(i, i);
        
    end 
end



fprintf('\n\nRiesenie matice =\n\n');
disp(riesenie_matice);


end
