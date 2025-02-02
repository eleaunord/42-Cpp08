## STL (=Standard Template Library)
=> contient les containers et les algorithmes 

Containers

La list : std::list<int> => containers templaté sur int aka ca va contenir des int

iterator : std::list<int>::const_iterator it;
std::list<int>::const_iterator ite = lst1.end(); => pas le dernier élément mais une valeur qui signifie qu'on a dépassé le dernier élément ; on l'utilise pour comparer au premier iterator. 
=> équivalent pointer 

for (it ) lst1.begin(); it != ite ; ++it)
{
	std::cout << *it << std::endl;
}

La map : std::map<std::string, IOperation*> => map IOperation indexé sur des string, je peux accéder à IOperation avec les string qui les correspond : map1["opA"] = new OperationA;

Le vector : tableau qui peut contenir ce qu'on veut. v1 ou v2(42,100) aka 42 entrées qui vont contenir 100.

Algorithmes
= fonctions pré implementés qui peuvent opérés sur des collections et qui vont effectué des opérations standards

for_each(lst.begin(), lst.end(), displayInt); => pour chaque int contenue dans notre list on va afficher le int

## Exercise 02: Mutated abomination

std::stack est un conteneur très pratique, mais il n’a pas d’itérateurs. Cela veut dire qu’on ne peut pas parcourir ses éléments avec une boucle for comme on le ferait avec std::vector ou std::list.
Std::stack est un adaptateur de conteneur aka il utilise un autre conteneur en arrière-plan pour stocker ses données.
Comme std::stack utilise un conteneur interne (aka la structure de données sous-jacente qui stocke réellement les éléments de la pile (std::deque par défaut)), on va rendre ce conteneur accessible pour pouvoir itérer dessus.
On va hériter de std::stack et ajouter des fonctions begin() et end() qui retourneront des itérateurs du conteneur interne.
Si on crée un std::stack<int>, en interne, il stocke les éléments dans un std::deque<int>, même si on ne le voit pas directement.

En bref, std::stack range ses éléments dans un autre conteneur (par défaut, un std::deque), mais il ne nous permet pas d’y accéder directement avec une boucle for. En ajoutant les fonctions begin() et end(), on donne accès aux outils qui permettent de parcourir facilement ces éléments, comme si std::stack était un conteneur classique.
