void err(struct lwct_state *S)
{
        lwct_assert(S, 1);
        lwct_assert(S, 0);
}

void ok(struct lwct_state *S)
{
        lwct_assert(S, 1);
        lwct_assert(S, 2);
}

int main(void)
{
        lwct_submit_test(err);
        lwct_submit_test(ok);
}
