#pragma once

struct list_elem {
	int key;
	list_elem* next, * prev;
};

list_elem* list_init()
{
	list_elem* root = nullptr;
	return root;
}

void list_insert(list_elem*& head, int value)
{
	list_elem* newNode = new list_elem;
	newNode->key = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (head == nullptr) {
		head = newNode;
		head->next = head;
		head->prev = head;
	}
	else {
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
	}
}

void remove(list_elem*& head, int key) {
	if (head == nullptr) {
		return;
	}

	list_elem* current = head;
	list_elem* toRemove = nullptr;

	do {
		if (current->key == key) {
			toRemove = current;
			break;
		}
		current = current->next;
	} while (current != head);

	if (toRemove == nullptr) {
		return;
	}

	list_elem* prevNode = toRemove->prev;
	list_elem* nextNode = toRemove->next;

	prevNode->next = nextNode;
	nextNode->prev = prevNode;

	if (toRemove == head) {
		if (head == head->next) {
			head = nullptr;
		}
		else {
			head = nextNode;
		}
	}

	delete toRemove;
}

void list_erase(list_elem*& head) {
	if (head == nullptr) {
		return;
	}

	list_elem* current = head;
	list_elem* nextNode = nullptr;

	do {
		nextNode = current->next;
		delete current;
		current = nextNode;
	} while (current != head);

	head = nullptr;
}

std::string print_list(list_elem* root, bool color) {
    std::string result = "";
	if (color) result += "BLACK ";
	else result += "RED ";
    if (root != nullptr) {
        list_elem* temp = root;

		do {
            result += "[ "+ std::to_string(temp->key) + " ] ->";
            temp = temp->next;
        } while (temp != root);
    }

    return result;

}

