#include "account.h"
#include "sql.h"

account::account()
{
    username = "";
    password = "";
    key = 0;
}

account::account(QString x, QString y, int z)
{
    username = x;
    password = y;
    key = z;
}

void account::setPassword(QString password)
{
    this->password = password;
}

/**
 * @brief returns password of the user
 * @return QString
 */
QString account::getPassword()
{
    return password;
}


void account::setKey(int key)
{
    this->key = key;
}

/**
 * @brief returns password
 * @return
 */
int account::getKey()
{
    return key;
}

/**
 * @brief encrypts password with key with ceasar cipher
 * @param password
 * @param key
 * @return QString
 *
 * encrypts password with ceasar cipher
 * that is increases the character with key, i.e if character is 'a' and key is 5, the character changes to 'f'
 * if the key is greater than the remaining character, the character cycles back to 'a'
 */
QString account::encrypt(QString password, int key){
    std::string pass = password.toStdString();

    /*loop for 0 to length of password*/
    for (int i = 0; i < password.length(); i++){
        /*if the character is not null*/
        if (pass[i] != '\0'){
            /*if the character is a lowercase letter*/
            if (pass[i] >= 'a' && pass[i] <= 'z'){
                /*adding key to character to change it*/
                pass[i] -= 26;
                pass[i] += key;

                /*if character is out of range of the lowercase letters*/
                if (pass[i] < 97){
                    /*cycles back from 'a'*/
                    pass[i] += 26;
                }
            }

            /*if character is uppercase letter*/
            if (pass[i]>='A' && pass[i]<='Z'){
                /*adding key to character to change it*/
                pass[i] += key;

                /*if character is out of range of the uppercase letters*/
                if (pass[i] > 90){
                    /*cycles back from 'A'*/
                    pass[i] -= 26;
                }
            }

            /*if character is a number*/
            if (pass[i] >= '0' && pass[i] <= '9'){
                /*if key is greater than 10, optimize the key since 13 and 3 is same*/
                int tempkey = key;
                if (key > 10){
                    tempkey = key % 10;
                }

                /*adding key to character to change it*/
                pass[i] += tempkey;

                /*if character is out of range of the uppercase letters*/
                if (pass[i] > 57){
                    /*cycle back from '0'*/
                    pass[i] -= 10;
                }
            }
        }else{
            break;
        }
    }
    return QString::fromStdString(pass);
}


/**
 * @brief decrypts an encrypted password with help of key
 * @param encryptedPassword
 * @param key
 * @return decrypted password
 *
 * decrypts password with ceasar cipher
 * that is decreases the character with key, i.e if character is 'f' and key is 5, the character changes to 'a'
 * if the key is greater than the remaining character, the character cycles back to 'z'
 */
QString account::decrypt(QString encryptedPassword, int key)
{
    std::string pass = encryptedPassword.toStdString();

    /*loop for 0 to length of password*/
    for (int i = 0; i < encryptedPassword.length(); i++){
        /*if the character is not null*/
        if (pass[i] != '\0'){
            /*if the character is a lowercase letter*/
            if (pass[i] >= 'a' && pass[i] <= 'z'){
                /*subtract key from character to change it*/
                pass[i] -= key;

                /*if character is out of range of the lowercase letters*/
                if (pass[i] < 97){
                    /*cycles back from 'z'*/
                    pass[i] += 26;
                }
            }
            /*if the character is a upper letter*/
            if (pass[i] >= 'A' && pass[i] <= 'Z'){
                /*subtract key from character to change it*/
                pass[i] -= key;

                /*if character is out of range of the lowercase letters*/
                if (pass[i] < 90){
                    /*cycles back from 'z'*/
                    pass[i] += 26;
                }
            }
            if (pass[i] >= '0' && pass[i] <= '9'){
                /*if key is greater than 10, optimize the key since 13 and 3 is same*/
                int tempkey = key;
                if (key > 10){
                    tempkey = key % 10;
                }

                /*subtract key from character to change it*/
                pass[i] -= tempkey;

                /*if character is out of range of numbers*/
                if (pass[i] < 48){
                    pass[i] += 10;
                }
            }
        }else{
            break;
        }
    }
    qDebug()<<"Decrypted Key:"<<QString::fromStdString(pass);
    return QString::fromStdString(pass);
}

void account::keyGenerator(void)
{
    qint32 key_admin = QRandomGenerator::global()->bounded(1,26);
    key = int (key_admin);
}
