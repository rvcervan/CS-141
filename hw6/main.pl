my_reverse(Reg, Rev):- my_reverse(Reg, [], Rev).

my_reverse([], Rev, Rev).
my_reverse([H|T], Prev, Rev):- my_reverse(T, [H|Prev], Rev).


my_length([], 0).

my_length([H|T], R):-my_length(T, Tlength), R is Tlength+1.


my_subset(Rel, [], []).
my_subset(Rel, [H|T], [H|NewT]):- Result =.. [Rel, H], Result,  my_subset(Rel, T, NewT).
my_subset(Rel, [_|T], NewT):- my_subset(Rel, T, NewT).


my_member(E, [E|T]).
my_member(E, [H|T]):-  my_member(E, T).

my_intersect([], _, []).
my_intersect([H|T], L2, [H|NewT]):- my_member(H, L2), my_intersect(T, L2, NewT).
my_intersect([H|T], L2, NewT):- my_intersect(T, L2, NewT).


compose([], [], []).
compose([H], [], [H]).
compose([], [H2], [H2]).
compose([H|T], [H2|T2], [H,H2|NewT]):- compose(T, T2, NewT).


palindrome(Reg, Rev):- palindrome(Reg, [], Rev).
palindrome([], Rev, Rev).
palindrome([H|T], Prev, [H|Rev]):-palindrome(T, [H|Prev], Rev).