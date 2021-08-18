% question 2
% facts about your house, real or imaginary
% door_between(entrance, living_room).
% door_between(living_room, kitchen).
% door_between(living_room, garage).
% door_between(living_room, hall).
% door_between(hall, bathroom_1).
% door_between(hall, room_1).
% door_between(hall, room_2).
% door_between(hall, room_3).
% door_between(room_3, bathroom_2).

% door_between(a, b).
% door_between(a, c).
% door_between(a, d).
% door_between(b, c).
% door_between(b, e).
% door_between(d, c).
% door_between(d, e).
% door_between(e, c).

path_from(A, B, [A, B]):- door_between(A, B).
path_from(A, B, [A|NewB]:- door_between(A, ToB), path_from(ToB, B, NewB).

% question 3

male(klefstad).
male(bill).
male(mark).
male(isaac).
male(fred).

female(emily).
female(heidi).
female(beth).
female(susan).
female(jane).

speaks_lang(klefstad, english).
speaks_lang(bill, english).
speaks_lang(emily, english).
speaks_lang(heidi, english).
speaks_lang(isaac, english).

speaks_lang(beth, french).
speaks_lang(mark, french).
speaks_lang(susan, french).
speaks_lang(isaac, french).

speaks_lang(klefstad, spanish).
speaks_lang(bill, spanish).
speaks_lang(susan, spanish).
speaks_lang(fred, spanish).
speaks_lang(jane, spanish).

already_in(P, List).

party_seating([]).
party_seating([H|T]):- 















