gcd(A, B, C) :- A = B, B = C.
gcd(A, B, C) :- A > B,
		D is A - B,
		gcd(D, B, C).
gcd(A, B, C) :- B > A,
		D is B - A,
		gcd(A, D, C).

fact(X, Y) :- 	X > 0, 
		V is X - 1,
		fact(V, Z),
		Y is X * Z.

fact(0, 1).


mem(X, [X|Y]).
mem(X, [Z|Y]) :- mem(X, Y).

rev([H|T], R, A) :- rev(T, [H|R], A).
rev([], R, R).


sumEven(
solve(A, B) :- (A * A) - (2 * (A * B)) + (3 * (B * B)) < 0.
factorial(0).
factorial(1).
sq(X, Y) :- Y is X * X.
