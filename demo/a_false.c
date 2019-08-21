int main(void)
{
        struct lwct_state *ls = lwct_init();
        lwct_assert(ls, 0);
        lwct_show_log(ls);
        lwct_destroy(ls);
}
