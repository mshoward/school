/* Suppose we have a family tree like this :
alan andrea   bruce betty      eddie elsie   fred  freda
 |     |        |     |          |     |       |     |
 |_____|        |_____|          |_____|       |_____|
    |              |                |             |
  clive        clarissa            greg         greta
   |  |__________|___|              |             |
   |__________|__|                  |_____________|
          |   |                            |
        dave doris                        henry

which is defined in Prolog by the following 3 sets of predicates:

*/

%   parent(Parent, Child).
%   Parent is the parent of Child.


grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
descendent(X, Y) :- parent(Y, X).
descendent(X, Y) :- grandparent(Y, X).
related(A, B) :- parent(C, A), parent(C, B).
related(A, B) :- descendent(A, B).
related(A, B) :- descendent(B, A).
related(A, B) :- descendent(A, C), descendent(B, C).
related(A, B) :- descendent(C, A), descendent(C, B).
canMarry(A, B) :- \+cannotMarry(A, B).

cannotMarry(A, B) :- (parent(C, A), parent(C,B)).
cannotMarry(A, B) :- parent(A, B).
cannotMarry(A, B) :- parent(B, A).
cannotMarry(A, B) :- grandparent(A, B).
cannotMarry(A, B) :- grandparent(B, A).
cannotMarry(A, B) :- (grandparent(C, A), parent(C, B)).
cannotMarry(A, B) :- (grandparent(C, B), parent(C, A)).
cannotMarry(A, B) :- (male(A), male(B)).
cannotMarry(A, B) :- (female(A), female(B)).




parent(alan, clive).
parent(andrea, clive).
parent(bruce, clarissa).
parent(betty, clarissa).
parent(clive, dave).
parent(clarissa, dave).
parent(clive, doris).
parent(clarissa, doris).
parent(eddie, greg).
parent(elsie, greg).
parent(fred, greta).
parent(freda, greta).
parent(greg, henry).
parent(greta, henry).


%   male(Person).
%   This Person is male.

male(alan).
male(bruce).
male(clive).
male(dave).
male(eddie).
male(fred).
male(greg).
male(henry).


%   female(Person).
%   This Person is female.

female(andrea).
female(betty).
female(clarissa).
female(doris).
female(elsie).
female(freda).
female(greta).


%   married(Person1, Person2).
%   Person1 is married to Person2.

married(alan, andrea).
married(bruce, betty).
married(clive, clarissa).
married(eddie, elsie).
married(fred, freda).
married(greg, greta).
