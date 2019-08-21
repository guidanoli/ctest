void err(struct lwct_state *ls)
{
        lwct_assert(ls, 1);
        lwct_assert(ls, 0);
}

void ok(struct lwct_state *ls)
{
        lwct_assert(ls, 1);
        lwct_assert(ls, 2);
}

int main(void)
{
        lwct_submit_test(err);
        lwct_submit_test(ok);
}
