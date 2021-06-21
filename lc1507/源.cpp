class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> s2month = {
            {"Jan", "01"},
            {"Feb", "02"},
            {"Mar", "03"},
            {"Apr", "04"},
            {"May", "05"},
            {"Jun", "06"},
            {"Jul", "07"},
            {"Aug", "08"},
            {"Sep", "09"},
            {"Oct", "10"},
            {"Nov", "11"},
            {"Dec", "12"}
        };
        stringstream ss(date);
        string y, m, d;
        ss >> d >> m >> y;
        d.pop_back();
        d.pop_back();
        m = s2month[m];
        if (d.size() == 1)
        {
            d = '0' + d;
        }
        return y + "-" + m + "-" + d;


    }
};