unique(X, [], N) :- N =< 1.
unique(X, [Y|Z], N) :- X =\= Y, unique(X, Z, N).
unique(X, [Y|Z], N) :- X =:= Y, Nupdate is N + 1, unique(X, Z, Nupdate).

uniqueAll([X|Y]) :- unique(X, [X|Y], 0), uniqueAll(Y).
uniqueAll([]).

isSudoku([	[A1,A2,A3, A4,A5,A6, A7,A8,A9],
			[B1,B2,B3, B4,B5,B6, B7,B8,B9],
			[C1,C2,C3, C4,C5,C6, C7,C8,C9],
			
			[D1,D2,D3, D4,D5,D6, D7,D8,D9],
			[E1,E2,E3, E4,E5,E6, E7,E8,E9],
			[F1,F2,F3, F4,F5,F6, F7,F8,F9],
			
			[G1,G2,G3, G4,G5,G6, G7,G8,G9],
			[H1,H2,H3, H4,H5,H6, H7,H8,H9],
			[I1,I2,I3, I4,I5,I6, I7,I8,I9]
		]) :- 	hasOneThruNine([A1,A2,A3, A4,A5,A6, A7,A8,A9]),
				uniqueAll([A1,A2,A3, A4,A5,A6, A7,A8,A9]),
				hasOneThruNine([B1,B2,B3, B4,B5,B6, B7,B8,B9]),
				uniqueAll([B1,B2,B3, B4,B5,B6, B7,B8,B9]),
				hasOneThruNine([C1,C2,C3, C4,C5,C6, C7,C8,C9]),
				uniqueAll([C1,C2,C3, C4,C5,C6, C7,C8,C9]),
				hasOneThruNine([D1,D2,D3, D4,D5,D6, D7,D8,D9]),
				uniqueAll([D1,D2,D3, D4,D5,D6, D7,D8,D9]),
				hasOneThruNine([E1,E2,E3, E4,E5,E6, E7,E8,E9]),
				uniqueAll([E1,E2,E3, E4,E5,E6, E7,E8,E9]),
				hasOneThruNine([F1,F2,F3, F4,F5,F6, F7,F8,F9]),
				uniqueAll([F1,F2,F3, F4,F5,F6, F7,F8,F9]),
				hasOneThruNine([G1,G2,G3, G4,G5,G6, G7,G8,G9]),
				uniqueAll([G1,G2,G3, G4,G5,G6, G7,G8,G9]),
				hasOneThruNine([H1,H2,H3, H4,H5,H6, H7,H8,H9]),
				uniqueAll([H1,H2,H3, H4,H5,H6, H7,H8,H9]),
				hasOneThruNine([I1,I2,I3, I4,I5,I6, I7,I8,I9]),
				uniqueAll([I1,I2,I3, I4,I5,I6, I7,I8,I9]),
				
				hasOneThruNine([A1,A2,A3, B1,B2,B3, C1,C2,C3]),
				uniqueAll([A1,A2,A3, B1,B2,B3, C1,C2,C3]),
				hasOneThruNine([A4,A5,A6, B4,B5,B6, C4,C5,C6]),
				uniqueAll([A4,A5,A6, B4,B5,B6, C4,C5,C6]),
				hasOneThruNine([A7,A8,A9, B7,B8,B9, C7,C8,C9]),
				uniqueAll([A7,A8,A9, B7,B8,B9, C7,C8,C9]),
				hasOneThruNine([D1,D2,D3, E1,E2,E3, F1,F2,F3]),
				uniqueAll([D1,D2,D3, E1,E2,E3, F1,F2,F3]),
				hasOneThruNine([D4,D5,D6, E4,E5,E6, F4,F5,F6]),
				uniqueAll([D4,D5,D6, E4,E5,E6, F4,F5,F6]),
				hasOneThruNine([D7,D8,D9, E7,E8,E9, F7,F8,F9]),
				uniqueAll([D7,D8,D9, E7,E8,E9, F7,F8,F9]),
				hasOneThruNine([G1,G2,G3, H1,H2,H3, I1,I2,I3]),
				uniqueAll([G1,G2,G3, H1,H2,H3, I1,I2,I3]),
				hasOneThruNine([G4,G5,G6, H4,H5,H6, I4,I5,I6]),
				uniqueAll([G4,G5,G6, H4,H5,H6, I4,I5,I6]),
				hasOneThruNine([G7,G8,G9, H7,H8,H9, I7,I8,I9]),
				uniqueAll([G7,G8,G9, H7,H8,H9, I7,I8,I9]),
				
				hasOneThruNine([A1,B1,C1, D1,E1,F1, G1,H1,I1]),
				uniqueAll([A1,B1,C1, D1,E1,F1, G1,H1,I1]),
				hasOneThruNine([A2,B2,C2, D2,E2,F2, G2,H2,I2]),
				uniqueAll([A2,B2,C2, D2,E2,F2, G2,H2,I2]),
				hasOneThruNine([A3,B3,C3, D3,E3,F3, G3,H3,I3]),
				uniqueAll([A3,B3,C3, D3,E3,F3, G3,H3,I3]),
				hasOneThruNine([A4,B4,C4, D4,E4,F4, G4,H4,I4]),
				uniqueAll([A4,B4,C4, D4,E4,F4, G4,H4,I4]),
				hasOneThruNine([A5,B5,C5, D5,E5,F5, G5,H5,I5]),
				uniqueAll([A5,B5,C5, D5,E5,F5, G5,H5,I5]),
				hasOneThruNine([A6,B6,C6, D6,E6,F6, G6,H6,I6]),
				uniqueAll([A6,B6,C6, D6,E6,F6, G6,H6,I6]),
				hasOneThruNine([A7,B7,C7, D7,E7,F7, G7,H7,I7]),
				uniqueAll([A7,B7,C7, D7,E7,F7, G7,H7,I7]),
				hasOneThruNine([A8,B8,C8, D8,E8,F8, G8,H8,I8]),
				uniqueAll([A8,B8,C8, D8,E8,F8, G8,H8,I8]),
				hasOneThruNine([A9,B9,C9, D9,E9,F9, G9,H9,I9]).
				uniqueAll([A9,B9,C9, D9,E9,F9, G9,H9,I9]).

hasNum(N, [X|Y]) :- X is N.
hasNum(N, [X|Y]) :- N =\= X, hasNum(N, Y).
hasOneThruNine(N) :- 	hasNum(1, N), hasNum(2, N),
						hasNum(3, N), hasNum(4, N),
						hasNum(5, N), hasNum(6, N),
						hasNum(7, N), hasNum(8, N),
						hasNum(9, N).




sudoku([
[6,5,1,4,9,8,2,3,7],
[8,3,7,5,2,6,4,9,1],
[9,4,2,1,3,7,6,5,8],
[2,9,4,7,6,5,8,1,3],
[3,1,6,9,8,4,5,7,2],
[5,7,8,3,1,2,9,6,4],
[1,8,3,2,5,9,7,4,6],
[7,2,9,6,4,3,1,8,5],
[4,6,5,8,7,1,3,2,9]]).
