
//Funcoes
function y = F(x)
    y(1) = -3*x(1) + 0.1*x(1)*x(1)+2*x(2) - 1
    y(2) = x(1) - 3*x(2) + 0.1*x(2)*x(2) + 2*x(3) - 1
    y(3) = x(2) - 3*x(3) + 0.1*x(3)*x(3) + 2*x(4) - 1
    y(4) = x(3) - 3*x(4) + 0.1*x(4)*x(4) + 2*x(5) - 1
    y(5) = x(4) - 3*x(5) + 0.1*x(5)*x(5) - 1
endfunction 

// Matriz Jacobiana
function y=JF(x)
    y(1,1) = 2*(0.1)*x(1) - 3
    y(1,2) = 2
    y(1,3) = 0
    y(1,4) = 0
    y(1,5) = 0
    y(2,1) = 1
    y(2,2) = 2*(0.1)*x(2) - 3
    y(2,3) = 2
    y(2,4) = 0
    y(2,5) = 0
    y(3,1) = 0
    y(3,2) = 1
    y(3,3) = (0.2)*x(3) - 3
    y(3,4) = 2
    y(3,5) = 0
    y(4,1) = 0
    y(4,2) = 0
    y(4,3) = 1
    y(4,4) = 2*(0.1)*x(4) - 3
    y(4,5) = 2
    y(5,1) = 0
    y(5,2) = 0
    y(5,3) = 0
    y(5,4) = 1
    y(5,5) = 2*(0.1)*x(5) - 3
endfunction

//Chute inicial
x = [0,0,0,0,0]';
norma = 1;
TOL = 1e-8;
cont =0;

//Iteracoes
//Metodo da inversa
while(norma >TOL)
    xp = x - inv(JF(x))*(F(x))
    norma = norm(xp-x, 'inf');
    x=xp;
    cont = cont + 1;
    
    disp("A solução é", xp)

    disp("iteraçao: ", cont)
 
end
