EntrolinealCompleta = importdata('output1_animation_entro_lineal_cylinder_extra2.txt');
numZ = 50;
figure

EntrolinealCompleta2=EntrolinealCompleta(10:1000,:);
h3=surf(linspace(0.02,0.98,48),linspace(0.001,0.1,991),EntrolinealCompleta2,'EdgeColor','none')
title('Evolución de la entropía local en el tiempo')
xlabel('z')
ylabel('tiempo(seg)') 
zlabel('entropía local(J/(Km))')
hold on
TemplinealCompleta = importdata('output1_animation_temp_lineal_cylinder_extra2.txt');
numZ = 50;
figure
TemplinealCompleta2=TemplinealCompleta(1:1000,:);
h4=surf(linspace(0.02,0.98,48),linspace(0,0.1,1000),TemplinealCompleta2,'EdgeColor','none')
title('Evolución de la temperatura de la varilla en el tiempo')
xlabel('z')
ylabel('tiempo(seg)')
zlabel('T(K)')
hold on
figure

Entrototalcompleta = importdata('output1_animation_entro_total_cylinder_extra2.txt');
h5=plot(linspace(0.001,0.1,4999),Entrototalcompleta)
title('Evolución de la entropía total en el tiempo')
xlabel('tiempo(seg)')
ylabel('entropía total(J/K)')
xlim([0 0.1])
ylim([0 inf])
M=min(Entrototalcompleta)
positiontemp=find(M)*0.001;
hold on
yline(M,'--b')
hold on
texto="Min = "+ M
text(0.002+positiontemp,M-1.3,texto)
estable=Entrototalcompleta(4999);
text(0.002+positiontemp,M-3,"En el estado estacionario entro = "+ estable)
hold on
