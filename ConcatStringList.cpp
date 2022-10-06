#include "ConcatStringList.h"
/*
ConcatStringList::ReferencesList ConcatStringList::refList = ConcatStringList::ReferencesList();
ConcatStringList::DeleteStringList ConcatStringList::delStrList = ConcatStringList::DeleteStringList();
*/

ConcatStringList::ConcatStringList(const char * s) {
    CharALNode *newNode = new CharALNode;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->CharArrayList = s;

    if(this->head == NULL)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next  = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int ConcatStringList::length() const {
    int count = 0;
    if (head != NULL)
    {
        CharALNode *temp = head;
        while (temp != NULL)
        {
            count += temp->CharArrayList.length();
            temp = temp->next;
        }
    }
    return count;
}

char ConcatStringList::get(int index) const {
    int length = this->length();
    char output;
    if ( index >= length || index < 0 )
    {
       throw out_of_range("Index of string is invalid!");
    }

    if (head != NULL)
    {
        CharALNode *temp = head;
        while (temp != NULL)        //duyet danh sach
        {
            if(index <= temp->CharArrayList.length()-1)     //so sanh index vs do dai cua tung node
            {
                output =temp->CharArrayList [index];
                break;         //neu oke thi tra ve vi tri thu index cua node do
            }
            else
            {
                index = index - temp->CharArrayList.length(); // kh oke thi lay index tru di do dai cua node vua roi va tiep tuc vong lap
            }
            temp = temp->next;
        }

    }
    return output;
}

int ConcatStringList::indexOf(char c) const {
    int count = 0;
    if (head != NULL)       //duyet tung node
    {
        CharALNode *temp = head;
        while (temp != NULL)
        {
            for ( int i = 0 ; i < temp->CharArrayList.length() ; i++)
            {
                if (temp->CharArrayList[i] == c) return count;
                count++;
            }
        }
    }
    return -1;
}

std::string ConcatStringList::toString() const {
    string output;
    if (head != NULL)       //duyet tung node
    {
        CharALNode *temp = head;
        while (temp != NULL)
        {
            output += temp->CharArrayList;
        }
    }
    return output;
}


ConcatStringList ConcatStringList::concat(const ConcatStringList &otherS) const {

}

ConcatStringList ConcatStringList::subString(int from, int to) const {

}

ConcatStringList ConcatStringList::reverse() const {

}

ConcatStringList::~ConcatStringList() {

}
