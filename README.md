# STL (=Standard Template Library)
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
