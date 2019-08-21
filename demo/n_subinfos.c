int is_prime(unsigned long p)
{
        if (p < 2) return 0;
        for (int i = 2; i <= p/2; i++)
                if (p % i == 0)
                        return 0;
        return 1;
}

void tester(struct lwct_state *ls, struct lwct_submission *info)
{
        unsigned long n = info->n_current + 1;
        lwct_assert(ls, is_prime(n));
}

int main(void)
{
        lwct_submit_batch(tester, 10);
}
