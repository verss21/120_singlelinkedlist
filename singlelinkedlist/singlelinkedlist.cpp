#include <iostream>
using namespace std;

struct Node {
	int noMhs;
	string name;
	Node* next;
};

Node* START = NULL;

void addNode() {
	int nim;
	string nama;
	Node* nodeBaru = new Node();
	cout << "Masukan NIM: ";
	cin >> nim;
	cout << "Masukkan Nama: ";
	cin >> nama;
	nodeBaru->noMhs = nim;
	nodeBaru->name = nama;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}

		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous = START;
	Node* current = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool serachNode(int nim, Node* current, Node* previous) {
	previous = START;
	current = START;
	while (current != NULL && nim > current->noMhs)
	{
		previous = current;
		current = current->next;
	}

		if (current == NULL)
		{
			return false;
		}
		else if (current->noMhs == nim)
		{
			return true;
		}
		else
		{
			return false;
	}
}
bool deleteNode(int nim) {
	Node* current = START;
	Node* Previous = START;
	if (serachNode(nim, Previous, current) == false)
		return false;
	Previous->next = current->next;
	if (current == START)
		START == current->next;
	return true;
}

bool listEmpty() {
	if (START == NULL)
		return true;
	else
		return false;
}

void traverse() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << "NIM : " << currentNode->noMhs << ", Nama : " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void searchData() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "Masukan NIM : ";
		cin >> nim;
		Node* currentNode = START;
		while (currentNode != NULL) {
			if (currentNode->noMhs == nim) {
				cout << "NIM : " << currentNode->noMhs << ", Nama : " << currentNode->name << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "data tidak ditemukan" << endl;
	}
}

int main() {
	int pilihan;
	do
	{
		try
		{
			cout << "1. Tambah data" << endl;
			cout << "2. Hapus data" << endl;
			cout << "3. Tampilkan data" << endl;
			cout << "4. Cari data" << endl;
			cout << "5. Keluar" << endl;
			cout << "Pilihan : ";
			cin >> pilihan;
			switch (pilihan)
			{
			case 1:
				addNode();
				cout << "Data Berhasil Ditambahkan" << endl;
				system("pause");
				system("cls");
			case 2:
				if (listEmpty())
				{
					cout << "List Kosong" << endl;
					system("pause");
					system("cls");
				}