#include "IParser.h"

class ParserJson : public IParser {
public:
    ParserJson();
    std::tuple<int, FieldData, std::vector<ShipData>> parse(const std::string& str) override;
    void parseAlgorithm(const std::string& stringToParse, 
                               const std::string& delimeter, std::queue<std::string>& returnParsedData) override;
};
