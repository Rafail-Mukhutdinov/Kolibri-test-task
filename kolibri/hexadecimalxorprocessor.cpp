#include "hexadecimalxorprocessor.h"

HexadecimalXORProcessor::HexadecimalXORProcessor() {}

QByteArray HexadecimalXORProcessor::processXOR(const QByteArray array, const QString &maskXor)
{

    if(maskXor.isEmpty()){ // Если маска XOR пуста
        return array; // Вернуть исходный массив
    }

    QByteArray HexadecimalXorKey = QByteArray::fromHex(maskXor.toLocal8Bit());
    QByteArray HexadecimalXorResult;
    HexadecimalXorResult.reserve(array.size()); // Резервирование памяти

    for(int i = 0; i < array.size(); ++i){
        HexadecimalXorResult.push_back(array[i] ^ HexadecimalXorKey[i % HexadecimalXorKey.size()]);
    }

    return HexadecimalXorResult;
}
