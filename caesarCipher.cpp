#include<iostream>

using namespace std;

string encrypt(string &str,int key){

    string encryptedMessage;

    for(int i = 0; i<str.size(); i++){
        if(islower(str[i])){
            encryptedMessage += char(int( str[i]+ key - 'a' ) % 26 + 97);
        }
        if(isupper(str[i])){
            encryptedMessage += char(int( str[i]+key - 'A') % 26 + 97);
        }
    }
     return encryptedMessage;
}

string decryptWithKey(string &encryptedMessage , int key){

    string decryptedMessage;

    decryptedMessage += encrypt(encryptedMessage, 26-key);

    return decryptedMessage;
}

void decryptWithoutKey(string &encryptedMessage){

    string decryptedMessage;

    for(int key = 1; key<=25; key++){
        decryptedMessage = decryptWithKey(encryptedMessage,key);
        cout<<decryptedMessage<<endl;
    }
}

void input(string &originalText, int &key){
    cout<<"Enter the original text = ";
    getline(cin,originalText);
    cout<<"Enter the key = ";
    cin>>key;
    key = key % 26;
}


int main()
{

    int option;

    cout<<"What you want to do? "<<endl;
    cout<<"1. Encryption"<<endl;
    cout<< "2. Decryption with given key"<<endl;
    cout<<"3. Decryption without key(brute force attack)"<<endl;
    cin>>option;
    getchar();
    //freopen("input.txt","r",stdin);

    string originalText, encryptedMessage,decryptedMessage;
    int key;
   
    switch(option)
    {
        case 1:
            input(originalText , key);
            encryptedMessage = encrypt(originalText, key);
            cout<<encryptedMessage;
            break;
        case 2:
            input(originalText, key);
            encryptedMessage = originalText;
            decryptedMessage = decryptWithKey(encryptedMessage,key);
            cout<<decryptedMessage<<endl;
            break;
        case 3:
            input(originalText,key);
            encryptedMessage = originalText;
            decryptWithoutKey(encryptedMessage);
            break;

        default:
            cout<<"You entered an invalid key. Please try again later."<<endl;
    }

    return 0;
}

