class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int last = 0;
        double tax = 0.0;
        for (auto bracket: brackets) {
            if (income <= 0) {
                break;
            }
            int here = bracket[0] - last;
            last = bracket[0];
            tax += 1.0 * min(income, here) * bracket[1] / 100.0;
            income -= here;
        }
        return tax;
    }
};
