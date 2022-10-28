int CQuickMedian(int *pnData, const int knLength)
{
    int nLow = 0;
    int nHigh = 0;
    int nMiddle = 0;
    int nMedian = 0;
    int nLTmp = 0;
    int nHTmp = 0;
    nMedian = (knLength - 1) >> 1;
    nHigh = knLength - 1;
    while (1)
    {
        if (nHigh == nLow)
        {
            return pnData[nHigh];
        }
        if (nHigh == nLow + 1)
        {
            return pnData[nHigh] > pnData[nLow] ? pnData[nLow] : pnData[nHigh];
        }
        nMiddle = (nHigh + nLow) >> 1;
        if (pnData[nLow] > pnData[nHigh])
        {
            CSwap(&pnData[nHigh], &pnData[nLow]);
        }
        if (pnData[nMiddle] > pnData[nHigh])
        {
            CSwap(&pnData[nMiddle], &pnData[nHigh]);
        }
        if (pnData[nMiddle] > pnData[nLow])
        {
            CSwap(&pnData[nMiddle], &pnData[nLow]);
        }
        CSwap(&pnData[nMiddle], &pnData[nLow + 1]);
        nLTmp = nLow + 2;
        nHTmp = nHigh - 1;
        while (1)
        {
            while (pnData[nLTmp] <= pnData[nLow])
            {
                nLTmp++;
            }
            while (pnData[nHTmp] >= pnData[nLow])
            {
                nHTmp--;
            }
            if (nLTmp > nHTmp)
            {
                CSwap(&pnData[nHTmp], &pnData[nLow]);
                if (nHTmp > nMedian)
                {
                    nHigh = nHTmp - 1;
                }
                else
                {
                    nLow = nLTmp - 1;
                }
                break;
            }
            else
            {
                CSwap(&pnData[nLTmp], &pnData[nHTmp]);
                nLTmp++;
                nHTmp--;
            }
        }
    }
}