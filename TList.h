#include <iostream>
#include <cmath>
using namespace std;
/*
Разработать шаблон списка, реализовав групповые добавление, удаление и замену элементов.
Группа представляется диапазоном итераторов.
Реализовать методы поиска элементов.
Добавить методы комбинирова¬ния списков как объединение и пересечение множеств.
*/

template <class T>
class TList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
public:
	class Iterator
	{
	public:
		typename TList<T>::Node* node;
		int index;
		Node* current;
		/*
		* Конструктор по умолчанию
		*/
		Iterator() {
			current = nullptr;
			node = NULL;
			index = -1;
		}
		/*
		* Конструктор с параметрами
		* @param node - указатель на корень списка
		* @param index - индекс узла
		*/
		Iterator(typename TList<T>::Node* node, int index) {
			this->current = node;
			this->node = node;
			this->index = index;
		}
		/*
		* Оператор увеличения итератора на 1
		*/
		Iterator operator++() {
			this->current = this->current->next;
			this->node = this->node->next;
			this->index++;
			return *this;
		}
		/*
		* Оператор увеличения итератора на n
		*/
		Iterator operator++(int) {
			Iterator temp = *this;
			this->current = this->current->next;
			this->node = this->node->next;
			this->index++;
			return temp;
		}
		/*
		* Оператор уменьшения итератора на 1
		*/
		Iterator operator--() {
			this->current = this->current->prev;
			this->node = this->node->prev;
			this->index--;
			return *this;
		}
		/*
		* Оператор уменьшения итератора на n
		*/
		Iterator operator--(int) {
			Iterator temp = *this;
			this->current = this->current->prev;
			this->node = this->node->prev;
			this->index--;
			return temp;
		}
		/*
		* Оператор разыменования итератора
		*/
		T& operator*() {
			return this->node->data;
		}
		/*
		* Оператор равенства итераторов
		* @param it сравниваемый итератор
		*/
		bool operator==(const Iterator& it) {
			return this->node == it.node;
		}
		/*
		* Оператор неравенства итераторов
		* @param it сравниваемый итератор
		*/
		bool operator!=(const Iterator& it) {
			return this->node != it.node;
		}
	};
	int size;
	/*
	* @brief конструктор по умолчанию
	*/
	TList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	/*
	* @brief деструктор
	*/
	~TList() {
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	/*
	* @brief добавление элемента в конец списка
	* @param data - добавляемый элемент
	*/
	void push_back(T data) {
		if (head == NULL)
		{
			head = new Node;
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
		}
		else
		{
			tail->next = new Node;
			tail->next->data = data;
			tail->next->next = NULL;
			tail->next->prev = tail;
			tail = tail->next;
		}
		size++;
	}
	/*
	* @brief добавление элемента в начало списка
	* @param data - добавляемый элемент
	*/
	void push_front(T data) {
		if (head == NULL)
		{
			head = new Node;
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
		}
		else
		{
			head->prev = new Node;
			head->prev->data = data;
			head->prev->next = head;
			head->prev->prev = NULL;
			head = head->prev;
		}
		size++; {
		}
	}
	/*
	* @brief удаление элемента из конца списка
	*/
	void pop_back() {
		if (head == NULL)
		{
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			Node* current = this->head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->prev->next = NULL;
			tail = current->prev;
			delete current;
		}
		size--;
	}
	/*
	* @brief удаление элемента из начала списка
	*/
	void pop_front() {
		if (head == NULL)
		{
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		size--; {
		}
	}
	/*
	* @brief удаление э-та по индексу
	* @param index - индекс удаляемого э-та
	*/
	void erase(Iterator it) {
		if (head == NULL)
		{
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			Node* current = this->head;
			while (current != it.current)
			{
				current = current->next;
			}
			if (current == head)
			{
				head = head->next;
				delete head->prev;
				head->prev = NULL;
			}
			else if (current == tail)
			{
				tail = tail->prev;
				delete tail->next;
				tail->next = NULL;
			}
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
				delete current;
			}
		}
		size--; {
		}
	}
	/*
	* @brief очистка списка
	*/
	void clear() {
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		head = NULL;
		tail = NULL;
		size = 0; {
		}
	}
	/*
	* @brief получение размера списка
	* @return размер списка
	*/
	int GetSize() { return size; }
	/*
	* @brief оператор доступа к э-ту по индексу
	* @param index - индекс э-та
	* @return э-т по индексу
	*/
	T& operator[](const int index) {
		int counter = 0;
		Node* current = this->head;
		while (current != NULL)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->next;
			counter++;
		}
	}
	/*
	* @brief вывод списка на экран
	*/
	void print() {
		Node* current = this->head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl; {
		}
	}
	/*
	* @brief групповое удаление э-тов
	* @param begin - итератор на первый удаляемый э-т
	* @param end - итератор на э-т, следующий за последним удаляемым
	*/
	*/
	void eraseGroup(Iterator begin, Iterator end) {
		if (begin == end)
		{
			return;
		}
		else
		{
			Node* current = this->head;
			int counter = 0;
			while (current != NULL)
			{
				if (counter == begin.index)
				{
					break;
				}
				current = current->next;
				counter++;
			}
			while (current != NULL)
			{
				if (counter == end.index)
				{
					break;
				}
				Node* temp = current;
				current = current->next;
				delete temp;
				size--;
				counter++;
			}
		}
	}
	/*
	* @brief добавление э-та по индексу
	* @param index - индекс э-та
	* @param data - добавляемый э-т
	*/
	void insert(Iterator it, T data) {
		if (it.index == 0)
		{
			push_front(data);
		}
		else
		{
			Node* current = this->head;
			int counter = 0;
			while (current != NULL)
			{
				if (counter == it.index)
				{
					Node* temp = new Node;
					temp->data = data;
					temp->next = current;
					temp->prev = current->prev;
					current->prev->next = temp;
					current->prev = temp;
					size++;
					break;
				}
				current = current->next;
				counter++;
			}
		}
	}
	/*
	* @brief замена э-та по индексу
	* @param index - индекс э-та
	* @param data - новый э-т
	*/
	void replace(Iterator it, T data) {
		Node* current = this->head;
		int counter = 0;
		while (current != NULL)
		{
			if (counter == it.index)
			{
				current->data = data;
				break;
			}
			current = current->next;
			counter++;
		}
	}
	/*
	* @brief поиск э-та по значению
	* @param data - искомый э-т
	* @return итератор на э-т
	*/
	Iterator find(T data) {
		Node* current = this->head;
		int counter = 0;
		while (current != NULL)
		{
			if (current->data == data)
			{
				return Iterator(current, counter);
			}
			current = current->next;
			counter++;
		}
		return Iterator(NULL, -1);
	}
	/*
	* @brief объединение списков
	* @param list - список, который нужно добавить
	*/
	void merge(TList<T>& list) {
		if (list.head == NULL)
		{
			return;
		}
		else
		{
			if (this->head == NULL)
			{
				this->head = list.head;
				this->tail = list.tail;
				this->size = list.size;
			}
			else
			{
				this->tail->next = list.head;
				list.head->prev = this->tail;
				this->tail = list.tail;
				this->size += list.size;
			}
			list.head = NULL;
			list.tail = NULL;
			list.size = 0;
		}
	}
	/*
	* @brief пересечение списков
	* @param list - список, с которым нужно пересечь
	*/
	void intersection(TList<T>& list) {
		if (list.head == NULL)
		{
			return;
		}
		else
		{
			Node* current = this->head;
			while (current != NULL)
			{
				if (list.find(current->data).index == -1)
				{
					Node* temp = current;
					current = current->next;
					erase(Iterator(temp, 0));
				}
				else
				{
					current = current->next;
				}
			}
		}
	}
	/*
	* @brief итератор на начало списка
	*/
	Iterator begin() {
		return Iterator(head, 0);
	}
	/*
	* @brief итератор на конец списка
	*/
	Iterator end() {
		return Iterator(tail, size - 1);
	}
	/*
	* @brief оператор вывода
	* @param out - поток вывода
	* @param list - список
	*/
	friend ostream& operator<<(ostream& out, const TList<T>& list) {
		Node* current = list.head;
		while (current != NULL)
		{
			out << current->data << " ";
			current = current->next;
		}
		return out;
	}
};