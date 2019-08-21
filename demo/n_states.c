int main(void)
{
        for(int i = 0; i < 3; i++) {
                struct lwct_state *ls = lwct_init();
                lwct_assert(ls, 1);
                lwct_show_log(ls);
                lwct_destroy(ls);
        }
}
