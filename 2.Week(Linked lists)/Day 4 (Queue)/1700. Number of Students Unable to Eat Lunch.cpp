class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> q(deque<int>(students.begin(), students.end()));
        int idx = 0, cnt = 0;
        int n = q.size();
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (curr != sandwiches[idx])
                cnt++, q.push(curr);
            else
                cnt = 0, idx++;
            if (cnt == n)
                break;
        }
        return q.size();
    }
};