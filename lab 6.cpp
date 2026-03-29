#include <iostream>
#include <string>

using namespace std;

class Message {
private:
    string Text;

public:
    Message() : Text("") {}

    Message(string TextValue) : Text(TextValue) {}

    void SetText(string Text) {
        this->Text = Text;
    }

    virtual string ToString() const {
        return Text;
    }
};

class SMS : public Message {
private:
    string RecipientContactNo;

public:
    SMS(string Contact, string Msg) : Message(Msg), RecipientContactNo(Contact) {}

    void SetRecipientContactNo(string Contact) {
        RecipientContactNo = Contact;
    }

    string GetRecipientContactNo() const {
        return RecipientContactNo;
    }

    string ToString() const override {
        return "To: " + RecipientContactNo + " | Message: " + Message::ToString();
    }
};

class Email : public Message {
private:
    string Sender;
    string Receiver;
    string Subject;

public:
    Email(string From, string To, string Sub, string Msg) 
        : Message(Msg), Sender(From), Receiver(To), Subject(Sub) {}

    void SetSender(string From) { 
        Sender = From;
    }
    void SetReceiver(string To) {
         Receiver = To; 
    }
    void SetSubject(string Sub) {
         Subject = Sub; 
    }

    string GetSender() const {
         return Sender; 
    }
    string GetReceiver() const {
         return Receiver;
     }
    string GetSubject() const {
         return Subject; 
    }

    string ToString() const override {
        return "From: " + Sender + " | To: " + Receiver + " | Subject: " + Subject + " | Message: " + Message::ToString();
    }
};

bool ContainsKeyword(const Message& MessageObject, const string& Keyword) {
    if (MessageObject.ToString().find(Keyword) != string::npos) {
        return true;
    }
    return false;
}

string EncodeMessage(string Input) {
    string EncodedText = Input;
    for (int I = 0; I < EncodedText.length(); ++I) {
        char C = EncodedText[I];
        if (C >= 'a' && C <= 'z') {
            EncodedText[I] = (C == 'z') ? 'a' : C + 1;
        } else if (C >= 'A' && C <= 'Z') {
            EncodedText[I] = (C == 'Z') ? 'A' : C + 1;
        }
    }
    return EncodedText;
}

int main() {
    SMS MySMS("555-0199", "Hello there");
    Email MyEmail("sender@test.com", "receiver@test.com", "Greetings", "This is Java");

    cout << MySMS.ToString() << endl;
    cout << MyEmail.ToString() << endl;

    string Keyword = "Java";
    if (ContainsKeyword(MyEmail, Keyword)) {
        cout << "Keyword '" << Keyword << "' found in email." << endl;
    }

    string Original = "This is Java";
    string Encoded = EncodeMessage(Original);
    cout << "Original: " << Original << endl;
    cout << "Encoded: " << Encoded << endl;

    return 0;
}
