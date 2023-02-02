#include "social_net.h"


int main()
{
    SocialNet sn;   
    sn.size = 0;
    setup_ABCDE_network(&sn);
    
    print_network(&sn);

    
    return 0;
}
