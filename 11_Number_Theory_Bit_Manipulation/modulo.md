## Addition 
(a+b)%m = ((a%m) + (b%m))%m

## Multiplication
(a*b)%m = ((a%m) * (b%m))%m

## Subtraction
(a-b)%m = ((a%m) - (b%m)+m)%m

## Division
(a/b)%m = ((a%m) * (b(inverse)))%m - b inverse is multiplicative inverse 
multiplicative inverse can be calculated using binary exponentiation or modular exponentiation