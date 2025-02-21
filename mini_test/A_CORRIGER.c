// pb segfault quand ligne vide --> REGLER

// pb $?  (exit status) --> pb d'env dans le parsing

// pb cat < hello | echo salut >> hello ne marche pas. creer bien hello avec salut 
// mais affiche minishell: hello: No such file or directory alors qu'il ne devrait pas. 
// par contre cat hello | echo salut > hello marche bien
// tout le monde ne le gere pas quasiement

// pb <<eof <<eof2 cat | <<eof3 cat --> REGLER j'ai gerer les here_doc dans les parents au lieu des enfants

// pb ctrl + C dans un here doc, sort de minishell --> REGLER on ne sort plus de ./minishell, juste du here_doc

// pb echo $USER ne fait rien --> pb parsing

// pb echo -n tout seul segfault --> REGLER en rajoutant "&& argv[i]""

// pb "cd .. hi" ne doit pas changer de dossier (too many argument) --> REGLER en rajoutant un truc pour prendre max 2 arg

// pb cd ne va pas au home --> pb parsing

// pb <Makefile echo bonjour ou <Makefile env --> REGLER on ne fait pas les builtin dans le parents si y a une redirection d'entree
// mais on aura un pb avec export qui va se faire dans un enfant, solution: sauvegarde de stdin 

// pb quand on fait deux fois make

// pb quand on fait cat | ls on boucle bien mais ca remet le prompte --> REGLER c'etait waitchildren qui etait mal fait
// j'ai rajouter int pid dans la structure de cmd et c'est bon 

// pb msg error parsing : 
// 						# Open pipe waits for input
// 							ls |
// 						# Undefined
// 							<<<
// 							<<<<
// 							> '
// 							echo hi |    |  < >>
// 							echo hi |  < >>   |  |
// on le gere bien mais faut mettre les msg en anglais

// pb exit quitte bien mais n'affichait pas exit avant --> REGLER

// export et unset a tester 

// pb boucle infini avec yes, quite bien avec ctrl + C 
// mais affiche deux fois le prompte --> REGLER mauvaise gestion des signaux 