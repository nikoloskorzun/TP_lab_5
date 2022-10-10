
#pragma once
using namespace std;
template<typename T>
class List
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext; //указатель на следующий элемент
		T data;//данные
		Node(T data = T(), Node* pNext = nullptr)

		{
			this->data = data;

			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;    //указатель на начало списка  

public:
	int GetSize() { return Size; }
	~List();
	List();
	void operator +(const T data);
	void pop_front();
	T& operator[](const int index);
	bool operator > (List& r);
	bool operator <(List& r);


};
template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = this->head;//âðåìåííàÿ ïåðåìåííàÿÿ, ïîêàçûâàþùàÿ êîíêðåòíûé ýëåìåíò
	int counter = 0;// ïåðåìåííàÿ ñ÷åò÷èê-ýëåìåíòîâ
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::operator+(const T data)
{
	head = new Node<T>(data, head);
	Size++;
}


template<typename T>
inline bool List<T>::operator>(List& r)
{
	if (this->GetSize() > r.GetSize())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline bool List<T>::operator<(List& r)
{
	if (this->GetSize() < r.GetSize())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}
template<typename T>
inline std::ostream& operator<<(std::ostream& os, List<T>& l)
{
	os << l.GetSize()<<endl	;
	for (int i = 0; i < l.GetSize(); i++)
		os << l[i];

	return os;


}

template<typename T>
inline std::ostream& Route_show(std::ostream& os, List<T>& l)
{
	os << "	Route:\n	  Length:";
	
	os << l.GetSize()<<endl;
	for (int i = 0; i < l.GetSize(); i++)
		City_show(os, l[i]);

	return os;


}

template<typename T>
inline std::istream& operator>>(std::istream& os, List<T>& l)
{
	


	int len_;
	
	os >> len_;
	for (int i = 0; i < len_; i++)
	{
		City *c = new City;
		

		os >> c->name;
		
		os >> c->cargo_size;
		
		os >> c->delicery_hours;
		l + (*c);
	}

	return os;
}


template<typename T>
inline std::istream& Route_input(std::istream& os, List<T>& l)
{
	
	


	int len_;

	cout << "input cities count\n";
		
	os >> len_;
	for (int i = 0; i < len_; i++)
	{
		City *c = new City;
		
			cout << "input city name\n";

		os >> c->name;
		
			cout << "input city cargo_size\n";
		os >> c->cargo_size;
		
			cout << "input city delicery_hours\n";
		os >> c->delicery_hours;
		l + (*c);
	}

	return os;
}




