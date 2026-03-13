clear; clc; close all;

%% --- USER INPUT ---
Nx = 128;          % must match simulation
Ny = 128;
Lx = 5.0;            % change per case
Ly = 5.0;
bx = 2;
by = 2;
A  = 0.01;

%% --- Load data ---
T_full = load(['T_',num2str(Nx),'.dat']);

Nx2 = Nx + 2;
Ny2 = Ny + 2;

% reshape (C++ is column-major flattened as i + j*Nx2)
T_full = reshape(T_full, [Nx2, Ny2]);

% remove ghost cells
T = T_full(2:end-1, 2:end-1);

% find average
Tavg = mean(T(:));

%% --- Create mesh ---
dx = Lx/Nx;
dy = Ly/Ny;

x = 0.5*dx + (0:Nx-1)*dx;
y = 0.5*dy + (0:Ny-1)*dy;

[X,Y] = meshgrid(x,y);

%% --- Create temperature plot --

% streamline function
Psi = -(A/(2*pi)) .* sin(2*pi*X./(bx*Lx)) .* sin(2*pi*Y./(by*Ly));

figure
contourf(Y,X,T,50,'LineColor','none')
clim([260.0 300.0])
colorbar
colormap("jet")
hold on

contour(X,Y,Psi,10,'k','LineWidth',1)

xlabel('x')
ylabel('y')
title('Temperature Plot with Space Heater')
subtitle(['Average Temperature = ', num2str(Tavg,'%.2f'),' K'])
axis equal tight
