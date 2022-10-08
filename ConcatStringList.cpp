#include "ConcatStringList.h"
/*
ConcatStringList::ReferencesList ConcatStringList::refList = ConcatStringList::ReferencesList();
ConcatStringList::DeleteStringList ConcatStringList::delStrList = ConcatStringList::DeleteStringList();
*/

CharALNode *CreatNewNode (string str)    /////// Tao newNode
{
    CharALNode *newNode = new CharALNode;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->CharArrayList = str;
    return newNode;
}

void AddNodeToLinkedList (CharALNode *newNode, ConcatStringList &output)
{
    if ( output.head == NULL)
    {
        output.head = newNode;
        output.tail = newNode;
    }
    else
    {
        output.tail->next = newNode;
        newNode->prev = output.tail;
        output.tail = newNode;
    }
}

ConcatStringList::ConcatStringList(){
    this->head = NULL;
    this->tail = NULL;
}

ConcatStringList::ConcatStringList(const char * s) {
    string str =s;
    CharALNode *newNode = CreatNewNode(s);

    this->head = newNode;
    this->tail = newNode;

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
            temp = temp->next;
        }
    }
    count = -1;
    return count;
}

std::string ConcatStringList::toString() const {
    string output;
    if (head != NULL)       //duyet tung node
    {
        CharALNode *temp = head;
        while (temp != NULL )
        {

            output += temp->CharArrayList;
            if( temp == tail) {break;}
            temp = temp->next;
        }
    }
    return output;
}


ConcatStringList ConcatStringList::concat(const ConcatStringList &otherS) const {
    ConcatStringList output;
    output.head = this->head;

    this->tail->next = otherS.head;
    otherS.head->prev = this->tail;
    output.tail = otherS.tail;
    return output;
}


ConcatStringList ConcatStringList::subString(int from, int to) const {
    if (from >= to) {                                            // xet cac truong hop de throw ra
        throw logic_error("Invalid range!");
    }

    if (from < 0 || to > this->length()) {
        throw out_of_range("Index of string is invalid");
    }

    ///////////////////
    ConcatStringList output; //tao ra cai output de return

    ///////////////////

    int index = to - from; //index = output.CharArrayList.length()

    ///////////////////
    while (this->head != NULL) {
        CharALNode *temp = this->head;
        while (temp != NULL)            //duyet tung node xet xem dua con tro dau vao vi tri nao? cua node nao?
        {
            if (from >= temp->CharArrayList.length()) //neu from > length cua 1 node
            {
                from = from - temp->CharArrayList.length();
                to = to - temp->CharArrayList.length();

                temp = temp->next;
            }
            else break;
        }
        ////////

        while (temp != NULL)    //con tro dang o node ma from < (node no dang o ).length()
        {
            string str;
            int conlai;  //so chu con lai tu "from" -> cuoi node

            conlai = temp->CharArrayList.length() - from;

            if ( index <= conlai)
            {
                int i = 0;
                while (index >i)
                {
                    str += temp->CharArrayList[from + i];
                    i++;
                }
                CharALNode *newNode = CreatNewNode(str);
                AddNodeToLinkedList(newNode, output);
                break;
            }

            else
            {
                for ( int i = from; i < temp->CharArrayList.length(); i++)
                {
                    str += temp->CharArrayList[i];
                    index--;
                }
                CharALNode *newNode = CreatNewNode(str);
                AddNodeToLinkedList(newNode, output);
                from = 0;
            }

            temp = temp->next;
        }

        ///////
        break;
    }
    return output;
}


void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i=0; i<n/2; i++)
        swap(str[i], str[n-i-1]);
}



ConcatStringList ConcatStringList::reverse() const {
    ConcatStringList output;

    if (head != NULL)
    {
        CharALNode *temp = tail ;
        while (temp != NULL)
        {
            string str = temp->CharArrayList;
            reverseStr(str);
            CharALNode *newNode = CreatNewNode(str);
            AddNodeToLinkedList(newNode, output);
            temp = temp->prev;
        }

    }

    return output;
}
/*
ConcatStringList::~ConcatStringList() {

}*/
