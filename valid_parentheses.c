bool isValid(char* s) {
    int n=strlen(s);
    if(n%2==1)
    {
        return false;
    }
    char stack[100005];
    int top=0;
    for(int i=0;s[i]!='\0';i++)
    {
        char c=s[i];
        if(c=='('||c=='['||c=='{')
        {
            stack[top++]=c;
        }
        else
        {
            if(top==0)
            {
                return false;
            }
            char t=stack[--top];
            if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{'))
            {
                 return false;
            }
            
        }
    }
    return top==0;
    
}
