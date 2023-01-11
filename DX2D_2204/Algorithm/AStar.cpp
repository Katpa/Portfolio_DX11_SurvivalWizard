#include "Framework.h"
#include "AStar.h"

AStar::AStar(InstancingMap* map)
{
    map->GetNodes(nodes);
    SetEdge(map->GetWidth());

    heap = new Heap();
}

AStar::~AStar()
{
    for (Node* node : nodes)
        delete node;

    delete heap;
}

void AStar::Update()
{
}

void AStar::Render()
{
    float R = CAM->GlobalPosition().x + WIN_WIDTH + 50;
    float L = CAM->GlobalPosition().x - 50;
    float T = CAM->GlobalPosition().y + WIN_HEIGHT + 50;
    float B = CAM->GlobalPosition().y - 50;

    for (Node* node : nodes)
    {
        if(node->pos.x < R && node->pos.x > L &&
            node->pos.y < T && node->pos.y > B)
        node->Render();
    }
        
}

int AStar::FindCloseNode(Vector2 pos)
{
    float minDist = FLT_MAX;

    int index = -1;

    for (UINT i = 0; i < nodes.size(); i++)
    {
        if (nodes[i]->state == Node::OBSTACLE)
            continue;

        float distance = Vector2::Distance(pos, nodes[i]->pos);

        if (minDist > distance)
        {
            minDist = distance;
            index = i;
        }
    }

    return index;
}

void AStar::GetPath(IN int start, IN int end, OUT vector<Vector2>& path)
{
    Reset();
    path.clear();

    //1. ���۳�� �ʱ�ȭ�ϰ� ���³�忡 �߰��ϱ�
    float G = 0;
    float H = GetDistance(start, end);

    nodes[start]->g = G;
    nodes[start]->h = H;
    nodes[start]->f = G + H;
    nodes[start]->via = start;
    nodes[start]->state = Node::OPEN;

    heap->Insert(nodes[start]);

    while (nodes[end]->state != Node::CLOSED)
    {
        //2. ���³�� �߿��� ȿ���� ���� ���� ��� ã��
        int curIndex = GetMinNode();
        //3. ã�� ���� ����� ����� ���� ������ ���³�忡 �߰��ϱ�
        Extend(curIndex, end);
        //4. Ȯ���� ���� ��� �ݱ�
        nodes[curIndex]->state = Node::CLOSED;
    }

    //5. ��Ʈ��ŷ
    int curIndex = end;
    while (curIndex != start)
    {
        nodes[curIndex]->state = Node::USING;
        path.push_back(nodes[curIndex]->pos);
        curIndex = nodes[curIndex]->via;
    }

    path.push_back(nodes[start]->pos);

    heap->Clear();
}

void AStar::Position(float x, float y)
{
    for (Node* node : nodes)
    {
        node->pos += Vector2(x, y);
    }
}

Vector2 AStar::FindWarpPos(Vector2 pos)
{
    int index = FindCloseNode(pos);

    return nodes[index]->pos;
}

void AStar::Reset()
{
    for (Node* node : nodes)
    {
        if (node->state != Node::OBSTACLE)
            node->state = Node::NONE;
    }
}

float AStar::GetDistance(int start, int end)
{
    Vector2 startPos = nodes[start]->pos;
    Vector2 endPos = nodes[end]->pos;

    Vector2 output = endPos - startPos;

    return output.Length();
}

void AStar::Extend(int center, int end)
{
    for (Node::Edge* edge : nodes[center]->edges)
    {
        int index = edge->index;

        if (nodes[index]->state == Node::CLOSED)
            continue;
        if (nodes[index]->state == Node::OBSTACLE)
            continue;

        float G = nodes[center]->g + edge->cost;
        float H = GetDistance(index, end);
        float F = G + H;

        if (nodes[index]->state == Node::OPEN)
        {
            if (F < nodes[index]->f)
            {
                nodes[index]->g = G;
                nodes[index]->f = F;
                nodes[index]->via = center;
            }
        }
        else if (nodes[index]->state == Node::NONE)
        {
            nodes[index]->g = G;
            nodes[index]->h = H;
            nodes[index]->f = F;
            nodes[index]->via = center;
            nodes[index]->state = Node::OPEN;

            //openNodes.push_back(index);
            heap->Insert(nodes[index]);
        }
    }
}

int AStar::GetMinNode()
{
    /*
    int openIndex = 0;
    int nodeIndex = openNodes[openIndex];
    float minF = nodes[nodeIndex]->f;

    for (UINT i = 0; i < openNodes.size(); i++)
    {
        nodeIndex = openNodes[i];
        if (nodes[nodeIndex]->f < minF)
        {
            minF = nodes[nodeIndex]->f;
            openIndex = i;
        }
    }

    nodeIndex = openNodes[openIndex];

    openNodes.erase(openNodes.begin() + openIndex);

    return nodeIndex;
    */

    return heap->DeleteRoot()->index;
}

void AStar::SetEdge(UINT width)
{
    for (UINT i = 0; i < nodes.size(); i++)
    {
        if (i % width != width - 1)
        {
            nodes[i]->AddEdge(nodes[i + 1]);
            nodes[i + 1]->AddEdge(nodes[i]);
        }

        if (i < nodes.size() - width)
        {
            nodes[i]->AddEdge(nodes[i + width]);
            nodes[i + width]->AddEdge(nodes[i]);
        }

        if (i % width != width - 1 && i < nodes.size() - width)
        {
            nodes[i]->AddEdge(nodes[i + width + 1]);
            nodes[i + width + 1]->AddEdge(nodes[i]);
        }

        if (i % width != 0 && i < nodes.size() - width)
        {
            nodes[i]->AddEdge(nodes[i + width - 1]);
            nodes[i + width - 1]->AddEdge(nodes[i]);
        }
    }
}