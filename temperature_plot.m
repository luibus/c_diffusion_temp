TempCompleta = importdata('output1_animation_temp_cylinder_extra2.txt');
%mi script para leer este archivo que tiene el ultimo paso de temperatura
%cada fila tiene distintos radios y cuando acaba pasa a los radios del
%siguiente angulo, luego en la siguiente linea pasa al siguiente Z, tarda
%mucho
%Z R RHO
%fil R col Z 
numZ = 50;
numR = 10;
numRHO = 9;
extremZ = 1;
extremR = 0.5;
Temp = TempCompleta(1:numZ,:);
Entro = TempCompleta(numZ+1:numZ*2,:);
Temp3d=zeros(numZ,numR,numRHO);
Entro3d=zeros(numZ,numR,numRHO);
for i=1:numRHO
    fprintf('%i\n', i)
    
    Temp3d(:,:,i) = Temp(:,int16(numR*(i-1)+1):int16(numR*(i)));
    Entro3d(:,:,i) = Entro(:,int16(numR*(i-1)+1):int16(numR*(i)));
end
figure
 for iZ=1:numZ
    for jR=1:numR
       for kRHO=1:numRHO
            z = ((iZ-1)*extremZ)/numZ;
            r = ((jR-1)*extremR)/numR;
            rho = ((kRHO-1)*2*3.1416)/numRHO;
           x = r * cos(rho);
           y = r * sin(rho);
      
           h1=scatter3(x,y,z, 3, Temp3d(iZ,jR,kRHO), 'filled');
          
           hold on
           %axis equal
           %box on
           %colorbar()
        end
    end
 end
title('Temperatura en el estado estacionario en el cilindro')
xlabel('X')
ylabel('Y') 
zlabel('Z')
%figure
%for iZ=1:numZ
%    for jR=1:numR
%        for kRHO=1:numRHO
%            z = ((iZ-1)*extremZ)/numZ
%            r = ((jR-1)*extremR)/numR;
%            rho = ((kRHO-1)*2*3.1416)/numRHO;
%           x = r * cos(rho);
%           y = r * sin(rho);
      
         
%           h2=scatter3(x,y,z, 3, Entro3d(iZ,jR,kRHO), 'filled');
%           hold on
%           %axis equal
%           %box on
%           %colorbar()
%        end
%    end
%end
%title('Entropía local en el cilindro')
%xlabel('X')
%ylabel('Y') 
%zlabel('Z')
% h1
% h2
