vector<int> stones(int n, int a, int b)
{
    vector<int> result;
    
    for (int i = 0, j = n-1; i < n && j >= 0; ++i, --j)
    {   
        int item = a*i + b*j;
        result.push_back(item);          
    }
    
    std::sort(result.begin(), result.end());
    auto it = std::unique(result.begin(), result.end());
    result.erase(it, result.end());
    
    return result;
}


vector<int> stones1(int n, int a, int b)
{
    vector<int> result;
    
    for (int i = 0, j = n-1; i < n && j >= 0; ++i, --j)
    {   
        int item = a*i + b*j;
        result.emplace_back(item);          
    }
    
    std::sort(result.begin(), result.end());
    auto it = std::unique(result.begin(), result.end());
    result.resize(std::distance(result.begin(), it));
    
    return result;
}
