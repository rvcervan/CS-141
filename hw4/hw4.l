(defun my-length (n)
	(cond
		((eq n nil) 0)
		(t (+ 1 (my-length(cdr n))))
	)
)


(defun my-memq (a b)
	(cond
		((eq b nil) nil)
		((eq a (car b)) b)
		(t(my-memq a (cdr b)))
	)
)

(defun my-append (a b)
	(cond
		(a (cons (car a) (my-append (cdr a) b)))
		(b (cons (car b) (my-append a (cdr b))))
	)
)

(defun my-attach(a b)
	(cond
		(b (cons (car b) (my-attach a (cdr b))))
		(t (cons a nil))
	)
)

(defun my-assoc(a L)
	(cond
		((eq L nil) nil)
		((eq a (car L)) L)
		((eq a (car(car L))) (car L))
		(t( my-assoc a (cdr L)))
	)
)

(defun freq (a L)
	(cond
		((null L)0)
		((eq a L)1)
		((listp L)(+(freq a (car L))(freq a (cdr L))))
		((atom L)0)
	)
)

(defun mapping (L a)
	(cond
		((null L) nil)
		((< a (car(car L)))(mapping(cdr L) a))
		(t (cons(car(cdr(car L))) (mapping(cdr L) a)))
	)
)

(defun my-last (a L)
	(cond
		()
		()
	)
)

(defun my-reverse (L) (rev2 L nil))
(defun rev2 (L R)
	(cond
		((null L) R)
		(T(rev2(cdr L)(cons(car L) R)))
	)
)

(defun is-pattern (L S)
	(cond 
		()
		()
	)
)

(defun first-atom (L)
	(cond
		((null L)nil)
		((atom L)L)
		(t(first-atom (car L)))
	)
)

(defun find-all (a L)
	(cond
		()
		()
	)
)
