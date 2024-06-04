#include <iostream>
using namespace std;

//task1
/* Написати функцію, яка для двох скінченних множин цілих чисел, 
поданих зв'язними впорядкованими списками, знаходить їхній перетин*/

//task1
void multilicationOfLists(list* head1, list* head2) {
	while (head1 && head2) {
		if (head1->num == head2->num) {
			cout << head1->num<<", ";
			head1 = head1->left;
			head2 = head2->left;
		} else {
      if (head1->num > head2->num)
				head2 = head2->left;
			else
				head1 = head1->left;
    }
	}
	cout << endl;
}
