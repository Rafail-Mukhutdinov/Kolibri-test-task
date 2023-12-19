#ifndef HEXADECIMALXORPROCESSOR_H
#define HEXADECIMALXORPROCESSOR_H

#include <QByteArray>
#include <QString>

class HexadecimalXORProcessor
{
public:
    HexadecimalXORProcessor();

    QByteArray processXOR(const QByteArray array, const QString &maskXor);

};

#endif // HEXADECIMALXORPROCESSOR_H
